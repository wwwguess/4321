// wanju2.c
// by dwolf

inherit ITEM;

void create()
{
        set_name("���", ({ "mian ju" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "���ƺ���һ���ɲ�֪ʲôƤ�Ƴɵ���ߡ�\n");
	}
	set("value",100);
        setup();
}

