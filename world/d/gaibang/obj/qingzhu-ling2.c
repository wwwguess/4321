// qingzhu-ling2.c ������

inherit ITEM;

void create()
{
        set_name("������", ({"qingzhu ling", "qingzhu", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�������ƾ�˿��������Ҫ�������\n");
                set("material", "steel");
		set("no_give_user", 1);
        }
}
