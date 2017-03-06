//ROOM:/d/suzhou/liushui.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

string *make_msg = ({
    HIG "你在急流中挣扎，挣扎－－－\n\n" NOR,
    HIG "你呛了一口水，又呛了一口－－－\n\n" NOR,
    HIG "你感到一阵发晕－－\n\n" NOR,
    HIG "突然你看到一点光亮，继续游!! \n\n" NOR,
});

void create()
{                           
	set("short", YEL"急流水"NOR);
	set("long", @LONG
       你在急流中挣扎，不时呛进一口水。你还有力气继续
游吗(swim)?
LONG
	);                                        
  	setup();   
}              
void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me;
        me = this_player();

//        me->move(__DIR__"shuidi");  
        remove_call_out("shuidi" );
        call_out( "shuidi", 2, me, 0 );
//	me->move(__DIR__"shuimian");
        return 1;
}
void shuidi(object who, int stage)
{                       
        tell_object(who, make_msg[stage]);
        
        if( ++stage < sizeof(make_msg) ) {
                call_out( "shuidi", 2, who, stage );
                return;
        } else   
//                message_vision(RED"ok\n"NOR, who);
                who->move("/d/suzhou/shuimian");
                who->add("kee", 100);
                who->add("gin", 100);
        tell_object(who, YEL "你终于又游了回来。\n" NOR);
        return;
}

