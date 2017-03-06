#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("乾坤大挪移心法",({ "skinbook","skin" }));
        set_weight(100);
        set("no_drop",1);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long",
                        "一卷羊皮，上面写着乾坤大挪移心法。\n");
                }

}
void init()
{
        add_action("do_study", "study");
}



int do_study(string arg)
{
        int lvl,exp,lit;
        object me;

        me=this_player();

if ( arg=="skin" || arg=="skinbook" )
{
        if ( (lit=(int)me->query_skill("literate", 1)) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if (me->query("sen") < 40)
                return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");

        me->add("sen", -30-random(10));

        message_vision("$N正专心研读乾坤大挪移心法。\n", me);

        exp=me->query("combat_exp")*10;       
     
        if ( (lvl=(int)me->query_skill("qiankun-danuoyi", 1)) < 180)
        {       
                if(lvl*lvl*lvl>exp) return 1;
                me->improve_skill("qiankun-danuoyi", (me->query("int")+lit/10)/3);
                write("你研读乾坤大挪移心法，似乎对乾坤大挪移有点心得。\n");
        } 
        else
        {  
                write("你对着羊皮琢磨了一回儿，发现上面所载的太过浅显，对你来说已毫无意义了。\n");
        }
 
        return 1;
}

        return notify_fail("什么？\n");


}
