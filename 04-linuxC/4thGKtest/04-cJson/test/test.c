#include    <stdlib.h>
#include    <stdio.h>
#include    <unistd.h>
#include    <string.h>
#include    "/usr/local/include/json/json.h"

void  GetValByKey(json_object * jobj, const  char  *sname)
{
    json_object     *pval = NULL;
    enum json_type type;
    pval = json_object_object_get(jobj, sname);
    if(NULL!=pval){
        type = json_object_get_type(pval);
        switch(type)
        {
            case    json_type_string:
                printf("Key:%s  value: %s\n", sname, json_object_get_string(pval));
                break;
            case    json_type_int:
                printf("Key:%s  value: %d\n", sname, json_object_get_int(pval));
                break;
            default:
                break;
        }
    }
}

int  main(void)
{
    json_object    *pobj = NULL;
#if 0
    pobj = json_tokener_parse("{ \"abc\": 12, \"foo\": \"bar\", \"bool0\": false, \"bool1\": true, \"arr\": [ 1, 2, 3, null, 5 ] }");

    printf("new_obj.to_string()=%s\n", json_object_to_json_string(pobj));

    //json_parse(pobj);
#else
    pobj = json_object_from_file("x.json");
    GetValByKey(pobj, "foo");


    json_object_object_del(pobj, "foo");
    json_object_object_add(pobj, "foo", json_object_new_string("fark"));
    json_object_object_add(pobj, "Age", json_object_new_int(200));
    GetValByKey(pobj, "Age");
    json_object_to_file("new.json", pobj);

    json_object_put(pobj);
#endif
    return 0;
}
