// Created by ysg
// data: 1997.10.17
//wig               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("��", ({ "shen fu" , "fu" }));
	set("title",YEL"�ϵ۱���"NOR);
	set("long",
	"һ����ë���۵��񸸣����ϲ������ƣ�һ˫������˪���֣�������һ�������۾������㡣\n");
	set("gender", "����");
	set("age", 65);
	set("attitude", "peaceful");
	set("combat_exp", 5000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"��˵���������ϵ۰ɣ��ϵۻᱣ����������ġ���\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}

