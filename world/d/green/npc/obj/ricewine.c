// Mon  08-21-95

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("�պ�", ({ "pottery" }) );
    set_weight(1000);
    if (clonep())
        set_default_object(__FILE__);
    else {
            set("long","һ���ֹ�������պ�, �����������Զ.\n");
            set("unit","��");
            set("value",0);
            set("max_liquid",10);
    }
    set("liquid", ([
        "type" : "alcohol",
        "name" : "�׾�",
        "remaining" : 7,
        "drunk_apply" : 7,
    ]) );
}

