import pandas as pd
import boto3
from datetime import datetime, timedelta
from boto3.dynamodb.conditions import Key
from decimal import Decimal


# sort key value for test_for_last_processed table
def get_sort_key(key):
	sort_key=key.split('/')[11].split('-')
	return sort_key[2]+"-"+sort_key[3]+"-"+sort_key[4]+" "+sort_key[5]+":"+sort_key[6]+":"+sort_key[7]


'''
PARAMETERS

    id_list: list of ids that will be read, example:  ["19-04211", "19-04212"]
    s_key=get_sort_key(key), sort key of current batch
    columns_list: columns to read, must given in a list format
    read_type: type of function that will be used to read from dynamodb, "read_from_dynamodb_by_time" or "read_from_dynamodb_by_batch"
    get_prev: if True start from one second before to read multiple ids
    
    to_time, batch_num, get_last_existing_value parameters should be given according to the functions to be used


read_cols_of_multiple_ids(ids=["19-04211", "19-04212"], s_key=get_sort_key(key),columns_list=["active","trial"], read_type="read_from_dynamodb_by_time", to_time="2023-03-22 19:16:47", get_prev=True, get_last_existing_value=False)

   read_from_dynamodb_by_time function reads the table with its to_time and get_last_existing_value parameters
   
read_cols_of_multiple_ids(ids=["19-04211", "19-04212"], s_key=get_sort_key(key),columns_list=["active","trial"], read_type="read_from_dynamodb_by_batch", batch_num=5, get_prev=True)

   read_from_dynamodb_by_batch function reads the table with its to_time and get_last_existing_value parameters

'''


def read_cols_of_multiple_ids(id_list, s_key, columns_list, read_type, to_time="", batch_num=1, get_last_existing_value=False, get_prev=True):
    
    dict_value={}
    read_types={
        "read_from_dynamodb_by_time":read_from_dynamodb_by_time,
        "read_from_dynamodb_by_batch":read_from_dynamodb_by_batch
    }
    params={
        "read_from_dynamodb_by_time":{
            "to_time":to_time,
            "get_last_existing_value":get_last_existing_value},
        "read_from_dynamodb_by_batch":{
            "batch_num":batch_num}
    }

    #update sort key to start to read from previous batch if get_prev is True 
    if get_prev:
        s_key=(datetime.strptime(s_key, "%Y-%m-%d %H:%M:%S")-timedelta(seconds=1)).strftime("%Y-%m-%d %H:%M:%S")    
    for idn in id_list:
        response = read_types[read_type](idn, s_key, columns_list, parameters=params[read_type], excludeCurrentBatch=False)
        print(idn)
        print(f'res {response}')
        dict_value.update({idn:response})
        print(dict_value)
    return dict_value


'''
OUTPUT
{'id_list[0]': 
    {'columns_list[0]': <NA>, 'columns_list[1]': <NA>},
 'id_list[1]': 
     {'columns_list[0]': 99.0, 'columns_list[1]': 3.0}
}

'''
