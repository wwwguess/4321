// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("��ؤ", ({ "beggar" , "kee gai" , "gai" }));
	set("long",
	"����һ����ʰ������������ؤ��\n");
	set("gender", "����");
	set("age", 20+random(30));
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 200);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
