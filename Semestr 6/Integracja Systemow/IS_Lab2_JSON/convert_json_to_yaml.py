# -*- coding: utf-8 -*-
"""
json to yaml converter
"""
import json
import yaml


class ConvertJsonToYaml:

    @staticmethod
    def run(deserializeddata, destinationfilelocation):
        print("let's convert something")
        with open(destinationfilelocation, 'w', encoding='utf-8') as f:
            yaml.dump(deserializeddata, f, allow_unicode=True)
        print("it is done")

    @staticmethod
    def run2(jsonfilelocation, destinationfilelocation):
        print("let's convert something")
        with open(jsonfilelocation, encoding='utf-8') as json_file:
            deserialized_data = json.load(json_file)
        with open(destinationfilelocation, 'w', encoding='utf-8') as f:
            yaml.dump(deserialized_data, f, allow_unicode=True)
        print("it is done")
