// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("��ʦ", ({ "biao shi", "biao" ,"shi" }));
	set("title",GRN"��Զ�ھ���ͷ"NOR);
	set("long",
	"������Զ�ھֵĻ�����ʦ��Ϊ�������ȣ����뵽���ڵ����С���������������Ҳ�㴳\n"
	"����һ��������\n");
	set("gender", "����");
	set("age", 20+random(20));
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 30000+random(5000));
	set_skill("dodge", 60);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
