

from .aws_backend import AwsBackend
from .azure_backend import AzureBackend
from .gcp_backend import GcpBackend

BACKENDS = dict()

BACKENDS['aws'] = AwsBackend
BACKENDS['gcp'] = GcpBackend
BACKENDS['azure'] = AzureBackend
