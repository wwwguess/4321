// jiading , added by kindman

inherit NPC;	

void create()
{
        set_name("�Ҷ�", ({ "jiading" }) );
        set("title", "�Ÿ��Ҷ�");
        set("gender", "����" );	 
        set("age", 35);
	set("long", 
		"�Ÿ��ļҶ���ٺ»���ߣ���Ȼ�����Ÿ������书Ҳ����\n");

	set("combat_exp", 40000);
	set_skill("dodge", 70);
	set_skill("parry", 90);
	set_skill("blade", 70);
	set_skill("spring-blade", 40);

	map_skill("blade", "spring-blade");

	setup();
	carry_object("/obj/weapon/blade")->wield();    
}


