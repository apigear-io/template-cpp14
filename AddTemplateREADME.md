# Add new template file
You can create your new template file to generate code and extend the current functionality to meet your needs. 

## Language
The language used for template files is liquid https://liquidjs.com/index.html

## Rules file
The recipe for generation of files is in rules.yaml file. 
The file lists all the features -if the feature is used in solution yaml, the generator goes through section with files listed for it and creates 
 - module files section - all the files for each module
 - interface files section - all the files for each interaface in each module
It requires the input file: path to existing document and a target path: file will be generated in that location with a given name.

You can add your own features there.
You can add new files that will be generated either for modules or for interfaces.

## Module and Interface variables
You can use module module variable which contains module related fields described in module yaml file (e.g. name, version)
- in rules.yaml file for module and interface related files e.g new file name
- inside generated files
You can use interface variable witch contains interface realted fields described in module yaml file (e.g. name, properties, operations, parameters)
- in rules.yaml file for interface related files e.g new file name
- inside generated files

The variables may be used with filters.

