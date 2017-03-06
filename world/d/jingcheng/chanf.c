#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"长安府"NOR);
	set("long", @LONG
这是长安城的行政机关，负责城里的大小事件。无论是偷鸡摸狗的小
贼，还是杀人放火的强盗，都会在这里受到应有的处罚。东边墙上贴
的是一些告示。
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"xchjie4", 
 
	]));
	setup();
	
}

void init()
{
//add_action("do_arrest","arrest");
add_action("do_loan" ,"loan");
add_action("do_withdraw", "withdraw");
add_action("do_balance","balance");
add_action("do_deposit", "deposit");
add_action("do_convert","convert");
}
int gethim(object target,object me)
{
        message_vision("$N一句话不说，匆匆忙忙地离开了。\n",target);
        target->move(this_object());
        message_vision("$N被官兵押了进来。\n",target);
	if(me){
	me->kill_ob(target);
	target->kill_ob(me);
		}
        return 1;
}
int do_arrest(string arg)
{
	object me, target;
	int exp, stra,leader,factor;
	if(!arg)
	return notify_fail("你要下令缉拿谁？\n");
	me = this_player();
	if((string) me->query("guantitle") == HIW"白丁"NOR )
	return notify_fail("你不是朝廷官员，不可缉拿疑犯！\n");
        if(!(me->query("guantitle")))
	return notify_fail("你不是朝廷官员，不可缉拿疑犯！\n");
	if((int) me->query("jingli") < 50 )
        return notify_fail("你的精力不够！\n");	
	me->add("jingli",-50);
	if(!objectp(target = find_living(arg)))
	return notify_fail("找不到你想要的疑犯！\n");
	if( interactive(target))
	return notify_fail("找不到你想要的疑犯！\n");
	if( target->query("no_arrest") )
	return notify_fail("找不到你想要的疑犯！\n");
	message_vision("$N大声下令道：来人那．．把$n给我拿来！！\n",me,target);
	exp = (int) target->query("combat_exp");
	stra = (int) me->query_skill("literate",1);
	leader = (int) me->query("chao_ting");
	factor = stra * stra * stra /40+leader;
	factor = (factor + ((int) me->query("combat_exp") ) - 2000 )/10;			
	if( random(factor) <= exp)
	return notify_fail("以你现在的能力，还不足以缉拿"+target->query("name")+"！\n");
	call_out("gethim",5,target,me);
	return 1;
}
