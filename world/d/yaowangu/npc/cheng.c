//NPC:/d/fgszhuang/npc/cheng.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;
string ask_for_yaowang();

void create()
{
	set_name(GRN"������"NOR, ({ "cheng linsu", "cheng"}) );
	set("gender", "Ů��" );
	set("age", 25);
        set("long",
		"����ҩ���Ĺ��ŵ��ӡ������ж�ҽѧ��\n");
	set("combat_exp", 300000);
	set("attitude", "friendly");  
	set("per", 25);
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",2);
        
	set("count", 1); 
	set("inquiry",([
                "ҩ��"  : (: ask_for_yaowang :),
        ]));   
	setup();
	add_money("silver",1);   
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();
}     

string ask_for_yaowang()
{
	object me;
	me = this_player();

	if(!(int)me->query("combat_exp")>=500000 )
	{
	return  "��ľ���̫�ͣ��������˰ɡ�\n";
        } else {
	if(query("count")<1)                                                
        	return "ʦ�������Ѿ�Ϊһ��������������ˣ������������ɡ�\n";
	add("count", -1);
	command("say ��ʦ�������棬�����\n");
	me->move("/d/yaowangu/ywgu2");
		return "�����ذ��Ŵ������ȥ���ֹ����ˡ�\n";  
	}
}
	
