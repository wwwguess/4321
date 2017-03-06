// seal.c write by sb 97.11.14

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;


inherit ITEM;
int do_scribe_haunt(string arg);
int do_haunt (string target, object who);
void create()
{
	set_name("符咒", ({"seal"}) );
	set_weight(5);
	set("long",
		"这是一张画好的符咒，用 burn 将它贴在某人(或某物)身上。\n");
	set("unit", "张");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}
void init()
{
add_action("do_warp", "burn");
}


int do_warp(string arg)
{
 
	string target, swho;
	object who;
if( !arg ) return notify_fail("你要在这张符上写谁的名字? \n");
    //    if( !arg || sscanf(arg, "%s %s", target, swho) != 2 )
	//	return notify_fail("你给的参数不正确\n");

//	if ( !objectp(	who = present(swho, environment(this_player())) ) )
//		return notify_fail ("你往哪儿贴？\n");
                   who=find_living("zombie");
	return do_haunt(arg, who);
}
	
int do_haunt(string target, object who)
{
        object dest,me;
         int ak,ep;

   //     if( !who->is_zombie() )
  //              return notify_fail(YEL "僵尸追魂符" NOR
//"只能用在僵尸身上。\n");

  //      if( !who->query("possessed") )
    //            return notify_fail("你必须先用法力镇住" + who->name() +
//"才能使用这道符。\n");

    me=this_player();ak=me->query_skill("spells");
 ep=me->query("combat_exp");who->set("combat_exp",ep);
                who->set_skill("unarmed",ak);
who->set_temp("apply/attack", ak);
	who->set_temp("apply/defense", ak);
    who->set("str",ak*2);
                 dest = present(target, environment(who));
        if( !dest ) dest = find_player(target);
        if( !dest ) dest = find_living(target);
        if( objectp(dest) ) {
                who->kill_ob(dest);
                who->set_leader(dest);
                              //  message_vision("$N眼睛忽然睁开，喃喃地说道：" RED
//"杀....死....$n....\n" NOR,
                    //    who, dest);
                if( environment(dest)==environment(who) ) {
                        dest->fight_ob(who);
		who->set("end_tag", 1);
                }
        } else {
                message_vision("$N眼睛忽然睁开，喃喃地说道：" RED
"杀....杀....杀....\n" NOR,
                        who);
                if( this_player() ) {
                        who->kill_ob(this_player());
                        who->set_leader(this_player());
                        this_player()->fight_ob(who);
                }
        }
	destruct(this_object());

        return 1;
}

