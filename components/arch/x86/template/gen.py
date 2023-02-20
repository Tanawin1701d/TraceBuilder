import yaml
import json

with open("uop.yaml", "r") as stream:
    try:
        data = yaml.safe_load(stream)
        print(data)
        print(json.dumps(data, indent=4))
    except yaml.YAMLError as exc:
        print(exc)


