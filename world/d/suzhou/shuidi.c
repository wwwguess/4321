//ROOM:/d/suzhou/shuidi.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

string *make_msg = ({
    HIG "你没有料到这平静的水一经你搅动就快速流动起来。\n\n" NOR,
    HIG "你顿时被急流冲了开去。\n\n" NOR,	
    HIG	"你在急流中挣扎，挣扎－－－\n\n" NOR,
    HIG "你呛了一口水，又呛了一口－－－\n\n" NOR,
    HIG "你感到一阵发晕－－\n\n" NOR,
    HIG "渐渐地你昏了过去。\n\n" NOR,
    HIG "你从昏迷中醒来，发现自己到了一个陌生的地方。 \n\n" NOR,
});

void create()
{                           
	set("short", RED"荷花池水底"NOR);
	set("long", @LONG
   	 你来到荷花池水底，这儿光线不足，只能依稀看见一些游鱼，还有
水草之类的东东，这里没有明显的出路，水流很慢，你可以游水(swim)，你想起传说中
的孙悟空在龙宫的故事，不由嘻嘻笑了。
LONG                            
	); 
	set("outdoors", "shuidi");                                       
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
      
//	me->move(__DIR__"liushui");  
	remove_call_out("shuidi" );
        call_out( "shuidi", 2, me, 0 );
//	me->move(__DIR__"liushui");
        return 1;
}

void shuidi(object who, int stage)
{     	                
        tell_object(who, make_msg[stage]);
     	
        if( ++stage < sizeof(make_msg) ) {
	        call_out( "shuidi", 2, who, stage );
		return;
        } else   
//		message_vision(RED"ok\n"NOR, who);
		who->move("/d/suzhou/liushui");
		who->add("kee", -200);
		who->add("gin", -150);
        tell_object(who, YEL "你终于停了下来!\n" NOR);
	return;
}
 

