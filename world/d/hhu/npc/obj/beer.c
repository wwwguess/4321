inherit ITEM;
inherit F_LIQUID;

void create()
{
       set_name("�����ơ",({"beer","wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",@LONG
��������ڵĽ����ơ��������(drink)һ�������ɿڵ�ơ�ư���
LONG
);
                set("value", 20);
                set("unit","ƿ");
                set("max_liquid", 30);
        }
        set("liquid", ([
                "name" : "ơ��",
        	"remaining" : 30,
        	"drunk_bonus" : 5,
        	"type" : "alcohol"
        ]) );
        setup();
}

