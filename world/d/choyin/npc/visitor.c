//traveller.c
inherit NPC;

void create()
{
        set_name("�ο�", ({ "visitor"}));
        if(random(10)<7)
            set("gender", "����" );
        else
            set("gender", "Ů��" );
        set("age", 15+random(50));
        set("long",
	"����һλ��������������ο͡�\n");

	set("env/wimpy",20);
	set("max_kee",1000);
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("dodge", 90);
        set_skill("unarmed", 76);
	set("str",20);
	set("cor",50);
	set_temp("apply/armor",30);
	
	set ("inquiry", ([
		"here": "�������������й���СС�������ض�������ʲô���ܣ�\n",
		"���ǲ�": "������������Ǹ�ʨ����ȥ�ˡ�\n",
		]) );

        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 5);
}



