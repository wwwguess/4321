// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("�ر���", ({ "qin baoguo", "qin" ,"baoguo" }));
	set("title",GRN"�������ܼ�"NOR);
	set("long",
	"�ر����ǽ������Ĺܼң�����ѵ���ظ����ӵ������书�����ǡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 50000);
	set_skill("dodge",50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"�ر�������˵������������������ǿ����ܱ�������\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
