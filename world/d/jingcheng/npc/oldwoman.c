// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("����", ({ "woman", "hu ren" }));
	set("title","Ӻ�ݻ���");
	set("long",
	"һ�����������������ӣ��ɷ��Զ�ž���ȥ�ˣ�������һ���ڼҡ�\n");
	set("gender", "Ů��");
	set("age", 33);
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 30);
	set("combat_exp", 1000);
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		"�Ϸ��˴������У���������������ǿ�������컯��������ɱ��������\n",                
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
