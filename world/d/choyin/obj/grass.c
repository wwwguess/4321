// grass.c

inherit ITEM;

void create()
{
        set_name("���ǲ�", ({ "grass" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ô���ɫ��С�ݣ����ž�Ө�Ĺ�â�����˵���ζ��\n");
                set("material", "paper");
                set("value", 10000);
        }
        setup();
}

