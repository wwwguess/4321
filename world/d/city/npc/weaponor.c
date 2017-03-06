// weaponor.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "weaponor" }) );
        set("title", "�������ƹ�");
        set("gender", "����" );
        set("age", 52);
        set("long", "�������Ǹ��뷢�԰׵����ˣ����������ѽ���ʮ�ꡣ\n");
        set("combat_exp", 120000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);

        set("inquiry", ([
                "����" : "����ר�����ֳ��̱���",
        ]) );
       set("vendor_goods", ([
		"��ͭս��": __DIR__"obj/armor1",
                "�����"  : __DIR__"obj/rain_whip",
                "���齣"  : __DIR__"obj/wuqing_sword",
                "���鵶"  : __DIR__"obj/duoqing_blade",
                "��ħ��"  : __DIR__"obj/demon_staff",
                "ţƤ��"  : "/obj/weapon/shield",
                "�˽Ǵ�"  : "/obj/weapon/sixhammer",
                "ϸ��"    : "/obj/weapon/thin_sword",
                "ذ��"    : "/obj/weapon/dagger",
                "�����": "/u/sbaa/mianju",
                "��Ѫ��": "/u/sbaa/sbsword",
                "������":"/u/sbaa/sbcloth",   
                "С¥һҹ������":"/u/sbaa/sbblade", 
        ]) );

        setup();
        add_money("silver", 50);
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
                        say( "������������λ"
                                + RANK_D->query_respect(ob)
                                + "���Ը�����һ�����ֵı����ɡ�\n");
                        break;
                case 1:
                        say( "�����������˵���͹��븶�ֳ���\n");
                        break;                       
                case 2:
say( "��������Ȼ���ƺ�������Զ�����������Ѻ͵���ͬ�����������Ρ�\n");
                        break;
        }
}

