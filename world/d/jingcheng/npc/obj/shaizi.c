// cloth.c
//
// This is the basic equip for players just login.

inherit ITEM;

void create()
{
        set_name("ɸ��", ({ "shai zi", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ����ͷɸ�ӡ�\n");
		set("unit", "��");
             }
        setup();
}

