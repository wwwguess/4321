// weaponor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "weaponor" }) );
        set("title", "������");
        set("gender", "����" );
        set("age", 32);
        set("long", "���������Ǹ������ˣ������˰̡�\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 60);

        set("inquiry", ([
                "������" : "����ר�����ֳ��̱���", 
        ]) );

        set("vendor_goods", ([
                "����": "/obj/weapon/whip",
                "����": "/obj/weapon/longsword",
                "����": "/obj/weapon/blade", 
                "����": "/obj/weapon/dart",
                "ţƤ��": "/obj/weapon/shield",
                "�˽Ǵ�": "/obj/weapon/sixhammer",
                "ϸ��": "/obj/weapon/thin_sword",
                "ذ��": "/obj/weapon/dagger.c",
        ]) );

        setup();
        add_money("silver", 5);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
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
                        say( "�������ӵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "���Ը�����һ�����ֵı�����\n");
                        break;
                case 1:
                        say( "��������ͻȻ������񣬺�����������������\n");
                        break;
        }
}

