// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}


void create()
{
        set_name("ɽ�軨", ({"shancha hua", "hua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ɽ�軨��\n");
                set("value", 115);
        }
        setup();
}


