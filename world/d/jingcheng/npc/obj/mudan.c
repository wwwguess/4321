// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}


void create()
{
        set_name("ĵ����", ({"mudan hua", "hua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ĵ������\n");
                set("value", 10);
        }
        setup();
}


