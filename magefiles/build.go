//go:build mage

package main

import (
	"fmt"
	"log"
	"os"
	"runtime"

	"github.com/apigear-io/helper"
	"github.com/magefile/mage/sh"
)

const (
	goldenDir = "goldenmaster"
	testDir   = "test"
)

func autoPlatform() (string, string) {
	return runtime.GOOS, runtime.GOARCH
}

func apigear() string {
	if runtime.GOOS == "windows" {
		return "apigear.exe"
	}
	return "apigear"
}

func gitClone(url, dir string) {
	helper.Must(sh.RunV("git", "clone", "--depth=1", url, dir))
}

func runDiff(dir1, dir2 string) {
	helper.Must(sh.RunV("git", "--no-pager", "diff", "--no-index", dir1, dir2))
}

func goInstall(pkg string) {
	helper.Must(sh.RunV("go", "install", pkg))
}
func genSol(sol string) {
	bin := helper.Join("bin", apigear())
	helper.Must(sh.RunV(bin, "generate", "solution", sol))
}

// Install installs the apigear cli and testbed-apis.
func Install() error {
	log.Printf("install apigear %s %s", runtime.GOOS, runtime.GOARCH)
	err := helper.MkDir("tmp")
	if err != nil {
		return err
	}
	err = helper.MkDir("bin")
	if err != nil {
		return err
	}

	// asset name we are looking for
	asset := fmt.Sprintf("apigear_%s_%s.zip", runtime.GOOS, runtime.GOARCH)
	asset_url := fmt.Sprintf("https://github.com/apigear-io/cli/releases/latest/download/%s", asset)
	err = helper.HttpDownload(asset_url, "tmp/"+asset)
	if err != nil {
		return err
	}
	err = helper.ExtractZipFile("tmp/"+asset, "bin")
	if err != nil {
		return err
	}

	src := helper.Join("tmp", apigear())
	dst := helper.Join("bin", apigear())
	helper.Rename(src, dst)
	os.Chmod(dst, 0755)
	helper.RmDir("tmp")
	return nil
}

// Diff runs the generator and compares the output with the golden master.
func Diff() {
	genSol("./apigear/goldenmaster.solution.yaml")
	runDiff(goldenDir, testDir)
}

// Clean removes all generated files.
func Clean() {
	helper.RmDir("bin")
	helper.RmDir(testDir)
}

// compares the goldenmaster files with the generated files
func DiffOnly() {
	runDiff(goldenDir, testDir)
}

// generate the goldenmaster files in the test directory
func GenTest() {
	helper.RmDir(testDir)
	genSol("./apigear/goldenmaster.solution.yaml")
}

// automatically format all goldenmaster files according to the clang-format
func FormatStyle() {
	helper.Must(sh.RunV("bash", "-c", "find goldenmaster -type f -iname '*.h' -o -type f -iname '*.cpp' | xargs clang-format -i"))
}

// test whether the goldenmaster files are formatted according to the clang-format
func TestStyle() {
	helper.Must(sh.RunV("bash", "-c", "clang-format --version && find goldenmaster -type f -iname '*.h' -o -type f -iname '*.cpp' | xargs clang-format --dry-run --Werror"))
}
