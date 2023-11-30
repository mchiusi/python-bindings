import cppyy
cppyy.include('HGCalHistoClusteringConfig_SA.h')

ClusterAlgoConfig = cppyy.gbl.l1thgcfirmware.ClusterAlgoConfig
config = ClusterAlgoConfig() #.setSector(3)
print(ClusterAlgoConfig)


