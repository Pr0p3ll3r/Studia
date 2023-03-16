import yaml
from deserialize_json import DeserializeJson
from serialize_json import SerializeJson
from convert_json_to_yaml import ConvertJsonToYaml

print("hey, it's me - Python!")

tempconffile = open('Assets/basic_config.yaml', encoding="utf8")
confdata = yaml.load(tempconffile, Loader=yaml.FullLoader)
newDeserializator = None

for operation in confdata['options']['operations']:
    if operation == 'deserialize_json':
        newDeserializator = DeserializeJson(confdata['paths']['source_folder'] + confdata['paths']['json_source_file'])
        newDeserializator.somestats()
    elif operation == 'serialize_json':
        if confdata['options']['source'] == 'file':
            SerializeJson.run(DeserializeJson(confdata['paths']['source_folder']+confdata['paths']['json_source_file']),
                              (confdata['paths']['source_folder']+confdata['paths']['json_destination_file']))
        elif confdata['options']['source'] == 'object':
            if newDeserializator is None:
                print("There is no object to serialize")
            else:
                SerializeJson.run(newDeserializator,
                                  (confdata['paths']['source_folder'] + confdata['paths']['json_destination_file']))
        else:
            print("Unknown source")
    elif operation == 'convert_json_to_yaml':
        if confdata['options']['source'] == 'file':
            ConvertJsonToYaml.run2((confdata['paths']['source_folder'] + confdata['paths']['json_destination_file']),
                                   (confdata['paths']['source_folder'] + confdata['paths']['yaml_destination_file']))
        elif confdata['options']['source'] == 'object':
            if newDeserializator is None:
                print("There is no object to serialize")
            else:
                ConvertJsonToYaml.run(newDeserializator, (confdata['paths']['source_folder'] +
                                                          confdata['paths']['yaml_destination_file']))
        else:
            print("Unknown source")
    else:
        print("Unknown operation")
