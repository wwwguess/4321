// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("������", ({ "tang zishou", "tang" ,"huoji" }));
	set("title",GRN"��Զ�ھ�������"NOR);
	set("long",
	"������Զ�ھֵ������֣������ܸɣ��ܵ�����ͷ�����Ρ�\n");
	set("gender", "����");
	set("age", 20+random(20));
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 10000+random(3000));
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_skill("blade", 30);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
