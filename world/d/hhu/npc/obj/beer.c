inherit ITEM;
inherit F_LIQUID;

void create()
{
       set_name("金陵干啤",({"beer","wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",@LONG
这可是正宗的金陵干啤，你好想喝(drink)一口清凉可口的啤酒啊！
LONG
);
                set("value", 20);
                set("unit","瓶");
                set("max_liquid", 30);
        }
        set("liquid", ([
                "name" : "啤酒",
        	"remaining" : 30,
        	"drunk_bonus" : 5,
        	"type" : "alcohol"
        ]) );
        setup();
}

