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
	set_name("����", ({"seal"}) );
	set_weight(5);
	set("long",
		"����һ�Ż��õķ��䣬�� burn ��������ĳ��(��ĳ��)���ϡ�\n");
	set("unit", "��");
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
if( !arg ) return notify_fail("��Ҫ�����ŷ���д˭������? \n");
    //    if( !arg || sscanf(arg, "%s %s", target, swho) != 2 )
	//	return notify_fail("����Ĳ�������ȷ\n");

//	if ( !objectp(	who = present(swho, environment(this_player())) ) )
//		return notify_fail ("�����Ķ�����\n");
                   who=find_living("zombie");
	return do_haunt(arg, who);
}
	
int do_haunt(string target, object who)
{
        object dest,me;
         int ak,ep;

   //     if( !who->is_zombie() )
  //              return notify_fail(YEL "��ʬ׷���" NOR
//"ֻ�����ڽ�ʬ���ϡ�\n");

  //      if( !who->query("possessed") )
    //            return notify_fail("��������÷�����ס" + who->name() +
//"����ʹ���������\n");

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
                              //  message_vision("$N�۾���Ȼ�������૵�˵����" RED
//"ɱ....��....$n....\n" NOR,
                    //    who, dest);
                if( environment(dest)==environment(who) ) {
                        dest->fight_ob(who);
		who->set("end_tag", 1);
                }
        } else {
                message_vision("$N�۾���Ȼ�������૵�˵����" RED
"ɱ....ɱ....ɱ....\n" NOR,
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

