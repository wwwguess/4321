// yuanbao.c 

#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY"��Ԫ��"NOR, ({"jin yuanbao" , "bao"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "yuanbao");
                set("long", "����һ����Ԫ������ӲӵĿ��Ŷ�ɰ�����\n");
                set("unit", "��");
                set("base_value", 10000);
                set("base_unit", "��");
                set("base_weight", 200);
        }
        set_amount(1);
}


