//mrfeng.c
//by dwolf
//97.11.9

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name(GRN"���˷�"NOR, ({ "miao renfeng","miao" }) );
	set("gender", "����" );
	set("age", 53);
	set("title",RED"�ɽ���"NOR);
	set("long", "�����ǵ����������˷Ҳ���Ǵ�ѩɽׯ��ׯ����������ȥ��ɫ��Ȼ��\n");

	set("combat_exp", 2000000);
	set("attitude", "peaceful");
	set("rank_info/respect", "����");    
	set("inquiry", ([
		"������" : "����СŮ�����֪�������Ķ���",
	]));

	setup();
	add_money("gold", 10);
}       

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        remove_call_out("greeting"); 
	call_out("greeting", 1, ob);    
	add_action("do_swear", "swear");
}
int accept_object(object me, object what)
{                                 
        if( !me->query("mark/����") ) return 0;
    	command("xixi");
        command("say ���Ȼ�����ң��Ҿ����㵽������ȡһ������ɡ����ҷ���(swear)ֻ��һ����\n");  
	me->delete("mark/����");
        remove_call_out("dest");
        call_out("dest", 1, what);
        return 1;                   
}
void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment() ) return; 
	command("say С�ֵ��ҵ����������СŮ����Ϣ��\n");
}                                   


int accept_fight(object me)
{
        command	("say ԭ������������������ģ�");
        command("chat ��λ����λ" + RANK_D->query_respect(me) + "�뵽��ѩɽׯ�����ң��ҾͲ������ˡ�\n"); 
        command("hehe");
        kill_ob(me);
        return 1;        
}              

int do_swear(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    

        if( arg=="ֻ��һ��"
	||  arg=="��ŵ��") 
	{
		command("haha");
		message("vision", MAG"���˷ﲻ֪��ô��$NŪ�ò����ˡ�\n"NOR, me);
		me->move("/d/xueshan/llou2");
		tell_room("/d/xueshan/llou2", RED"$N��Ȼ���������\n"NOR,me); 
		destruct(this_object());
		return 1;      
	}
}
                      

