// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit ROOM;

void init();
int do_lin(string);


void create()
{
        set("short", "达摩院二楼");
        set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不
少白须白眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。
南北山墙是高及屋顶的大书架，走近细看，它们是各门各派的武
功秘笈，屋正中摆着几张矮几诃和几个团，几位老僧正在入定中。
LONG
        );

        set("exits", ([
                "down" : __DIR__"dmyuan",
        ]));

        set("objects",([
                CLASS_D("shaolin") + "/xuan-bei" : 1,
                __DIR__"npc/xiao-bei" : 1,
        ]));
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_lin", "lingwu");
}


int do_lin(string arg)
{
   object me= this_player();
        object where = environment(me);
        string skillname;
        int skill, skill_basic;
        int cost; 

        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if( !arg ) return notify_fail("领悟什么？\n");

        skill_basic = me->query_skill(arg, 1);

        if( skill_basic < 1 )
         return notify_fail("你还没学过这项技能吧？最好先去请教别人。\n");

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
             return notify_fail("你只能领悟 enable 了高级技能的基本技能。\n");
        skill = me->query_skill(skillname, 1);

        if( skill_basic >= skill)
         return notify_fail("你的基本功夫比你的高级功夫还高！\n");
        cost=20;
        if( (int)me->query("sen") > cost ) {
          me->improve_skill(arg, random((int)me->query_int()*2)+1);
        
          write( HIY "你的" + to_chinese(arg) + "进步了！\n" NOR);
         } else {
           cost=me->query("sen");
           write("你现在过于疲倦,无法静下心来领悟功夫！\n");
         }

         me->receive_damage("sen", cost );
                return 1;
}

int valid_leave(object me, string dir)
{
        int i;
        if( present("nine book", this_player())
        && (objectp(present("xuanbei dashi", environment(me)))) )
        {
                if (dir == "down" && !(int)me->query("readed"))
                {    
                     me->set("readed",1);
                     i=(int)me->query("int");
                     i=i+5;
                     me->set("int",i);
		     i=(int)me->query("con");
	             i=i+5;
                     me->set("con",i);
                     i=(int)me->query("dex");
                     i=i+5;
                     me->set("dex",i);
                     i=(int)me->query("str");
                     i=i+5;
                     me->set("str",i);
                     write("玄悲突然说到:“施主所带这本梵文书，意思是\n");
                     write("天之道，损有余而补不足，是故需胜实，不足胜有余...”\n"); 
                     write("你百思不解的武学难题，豁然开朗。\n");
                     return ::valid_leave(me, dir);
                }
        }
        return ::valid_leave(me, dir);
}
