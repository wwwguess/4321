inherit ITEM;

void create()
{
        set_name("��������", ({ "token" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "һ֧��ʧ��������ƣ������ڳ���ʱ�����á�\n");
                set("value", 0);
                set("material", "copper");
        }
}

