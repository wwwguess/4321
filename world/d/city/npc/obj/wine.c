inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("״Ԫ��", ({"wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
          else {
        	set("long", "����һ̳��ζŨ���ĳ����Ͼƣ���ר��״Ԫ����ʱ�ȵľơ�\n");
                set("unit", "̳");
                set("value", 350);
                set("max_liquid", 30);
        }
        set("liquid", ([
                "name" : "���",
                "remaining" : 30,
                "drunk_bonus" : 7,
                "type" : "alcohol"
        ]) );
        setup();
}

