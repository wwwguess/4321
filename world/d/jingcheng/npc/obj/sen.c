#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(MAG"�˲�"NOR,({"sen"}) );
	set("long",	
		YEL"����һ���е���ɱ���ܲ��Ķ�������������һ���ϵ�ҩ�ĵ�ζ����\n"NOR);
	set("unit", "��");
	set("base_unit", "��");
	set("base_weight", 200);
set("value",100000);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int num= this_player()->query("max_gin");
	object ob=this_player();
         if( !arg || arg != "sen")  return notify_fail("^D^C^R^J^S^T^I^U^C^T^D^X? \n");
         if( (int)this_player()->query("combat_exp") < 100000 ){
                message_vision(
                   RED"$N�ó�һ���˲Σ�һ�ڸ�������ȥ��\n"
                   "$Nֻ�������Ȳ����ͣ��·�׹��һ�����¯��һ�㡣"
			 "��æ��ϥ�������˹��࿹��\n" NOR
			 ,this_player() );
        this_player()->set("force",(int)this_player()->query("force")/2 );
         ob->receive_heal("eff_gin", num);
	}
	else{
		message_vision(
		   YEL"$N�ó�һ���˲Σ�һ�ڸ�������ȥ��\n"
		   "$N�ĵ�����һ��������������������ȫ���澭��������ʱ��������\n"NOR,this_player() );
		if( (int)this_player()->query("force") <(int)this_player()->query("max_force") )
this_player()->set("force",(int)this_player()->query("max_force"));
        this_player()->set("eff_gin", num);
	}
	add_amount(-1);
	return 1;
}
