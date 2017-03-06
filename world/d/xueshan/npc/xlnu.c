//room: /d/fgszhuang/npc/xlnu.c
//by dwolf
//97.11.9

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(MAG"С��Ů"NOR, ({ "xiao longnu", "xiao" }) );
        set("title", "������Ů");
        set("gender", "Ů��" );
        set("age", 32);
        set("long", "����Сס�ڹ�Ĺ�У������������������ϧ������ʧɢ�ˡ�\n");
	set("str", 20);
	set("per", 40);      
	set("int", 25); 
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 150);
        set("combat_exp", 2000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 100);
        set_skill("parry", 200);
        set_skill("dodge", 200);
	set_skill("sword", 200);
	set_skill("force", 200);      
	set_skill("jiuyin", 200);
	set_skill("zhuifeng-liushi", 200);
	map_skill("dodge", "zhuifeng-liushi"); 
	map_skill("force", "jiuyin");

        set("inquiry", ([
		"���" : "��������Ī��֪���������Ķ������������Ǽ�����\n",
	]));
	
	create_family("��Ĺ��", 3, "����"); 
	
	setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/gangjian")->wield();

}

void init()
{                                     
	add_action("do_pray", "pray");
}     

int do_pray(string arg)
{                 
	object me,obj,ob;
	me = this_player();
	obj = this_object(); 
	
	if( !arg || arg=="" ) return 0;  
	
	if(query_temp("mark/been_done"))
	{      
		remove_call_out("done");
		call_out("done", 1, me); 
		command("waggle");
		return notify_fail("��̫̰���ˣ��������������ˡ�\n");
	}  

        if( arg=="�����˽Գɾ���" ||  arg=="�������") 
	{
		message("vision", RED"�����������Ը���������˶��ɾ�����\n"NOR, me);
		command("thank");
		ob = new(__DIR__"yguo2");
		ob->move("/d/xueshan/jqgdi");
		me->add("combat_exp", 2000);
		set_temp("mark/been_done", 1);
		tell_room("/d/xueshan/jqgdi", YEL"�����Ȼ���������С��Ů��ϲ��ӭ����ȥ��\n"NOR); 
		return 1;      
	}
}
                                 
void done(object me)
{
	command("thank");
}               
