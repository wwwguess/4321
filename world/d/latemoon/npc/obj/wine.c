inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("Ů����", ({"wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
   "����һ̳��ζŨ���ĳ����Ͼƣ��Ǵ������Ů���ȵľơ�\n"
   "�������ţ��������Ŷ!���е������ (drink)\n");
                set("unit", "̳");
                set("value", 20);
                set("max_liquid", 30);
        }
        set("liquid", ([
        	"name" : "���",
        	"remaining" : 30,
        	"drunk_bonus" : 5,
        	"type" : "alcohol"
        ]) );
        setup();
}

