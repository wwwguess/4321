inherit ITEM;

void create()
{
        set_name("��������", ({ "orchid" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�꺮��������ɢ���ŵ���������, ���ƺ�������ׯ�ŵ���.\n");
                set("material", "paper");
                set("value", 10000);
        }
        setup();
}

