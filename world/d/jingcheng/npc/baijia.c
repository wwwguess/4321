// Created by lysh
// data: 1997.10.17
              
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("�ܼ���", ({ "baijia zi" , "zi" }));
	set("title",HIC"���ֺ���"NOR);
	set("long",
	"һ����������ʵ�µİܼ��ӡ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("combat_exp", 100);
	setup();
        set("chat_chance", 10);
        carry_object(__DIR__"obj/shaizi");  
        carry_object(__DIR__"obj/cloth")->wear();

}

