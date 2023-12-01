import cppyy
cppyy.load_library('lib_configuration.so')
cppyy.include('HGCalHistoClusteringConfig_SA.h')

ClusterAlgoConfig = cppyy.gbl.l1thgcfirmware.ClusterAlgoConfig
config = ClusterAlgoConfig()

config.printConfiguration()
