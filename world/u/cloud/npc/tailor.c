// tailor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�÷�", ({ "tailor" }) );
        set("title", "��ׯ");
        set("gender", "����" );
        set("age", 42);
        set("long", "һλ����ȥ�ܺͰ����ϲ÷죬���ڷ����·���\n");
	set("str", 12);
	set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        set("inquiry", ([
		"������" : "��Ҳ֪��'�̺�����'����¥����б���棬�ҳ�ȥ�ġ�", 
        ]) );

        set("vendor_goods", ([
                "����": "/u/cloud/obj/cloth/cloth",
        ]) );

	setup();
	add_money("silver", 2);
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
	carry_object("/u/cloud/obj/npc/tailor/ruler");
	carry_object("/u/cloud/obj/npc/tailor/scissors")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�ϲ÷�̧��ͷ������һ�ۣ��ʵ����͹��򲼻�������?\n");
                        break;
                case 1:
                        say( "�÷���ֽ�������������Ȼ�����˶����ˡ�\n");
	}
}

