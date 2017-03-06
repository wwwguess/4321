// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("������", ({ "you xiaer", "youxia" }));
	set("title",GRN"��������"NOR);
	set("long",
	"ʱ������֮�����أ���������ͷҲ�ɿ�����װ�彣���ꡣ\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 30);
	set("combat_exp", 30000+random(5000));
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("sword", 70);
	set_temp("apply/defense", 20);
	set_temp("apply/attack", 20);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: random_move :),
        	"�����������������̽���������Ϸ�˼䣬���Ǻεȿ����ң֮�¡�\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	object obj;

	command("say "+RANK_D->query_respect(me)+"����һ�𴳵������ɡ�\n");
	command("smile");
	if( random(10) > 7 )
	{
		command("l "+me->query("id"));
		message_vision("��������$N˵������"+RANK_D->query_close(me)+
		"�������ո�ǿ���ɷ����ұȻ��Ȼ���\n",me);
		command("fight "+me->query("id"));
		return;
	} 
	switch( random(3) ){
		case 0:
			if( present(me->query("id"), environment(me)) ){
				command("pat "+(string)me->query("id"));
				if( me->query("gender") == "Ů��" )
				command("kiss "+me->query("id"));
			}
			break;	
		case 1:			
			command("haha");
			message_vision("�������γ���������������������Ц��:�㿴��Ư����\n");	
			break;
		default:
			if( present(me->query("id"), environment(me)) ){
				command("hi "+(string)me->query("id"));
				message_vision("��������Ц���������˷��ȥ�����˸��Ҷ����ᷢ��������\n");
				command("bye "+(string)me->query("id"));
				obj = new(__DIR__"obj/yuanbao");
				message_vision("����������$N���֣�����$Nһ��Ԫ����\n",me);
				obj->move(me);
				break;
			}
	}
	return;
}
