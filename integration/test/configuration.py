import cppyy
cppyy.include('HGCalHistoClusteringConfig_SA.cc')

config = cppyy.gbl.ClusterAlgoConfig()
config.setSector(3)
print(config.sector())

print(ClusterAlgoConfig)


