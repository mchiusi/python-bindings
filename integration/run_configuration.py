import cppyy
cppyy.load_library('lib_configuration.so')
cppyy.include('HGCalHistoClusteringConfig_SA.h')

import yaml
with open('config.yaml', "r") as afile:
    params = yaml.safe_load(afile)

enum = cppyy.gbl.l1thgcfirmware.Step
params['stepLatency'] = [{int(vars(enum)[latency]) : d[latency]} for d in params['stepLatency'] for latency in d.keys()]
print(params['stepLatency'])

ClusterAlgoConfig = cppyy.gbl.l1thgcfirmware.ClusterAlgoConfig
config = ClusterAlgoConfig(**params)

config.printConfiguration()
