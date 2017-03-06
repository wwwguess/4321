// clother.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�ϰ���", ({ "woman" }) );
        set("title", "���ׯ");
        set("gender", "Ů��" );
        set("age", 29);
        set("long", "�ϰ����ǲ��ѿ���Ů�ˣ�һֱ��Ӫ�ž��ǵĳ�����⡣\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("max_atman", 1000); 
        set("atman", 1000);        
       set("atman_factor", 3);
        set("max_force", 1000); 
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000); 
        set("mana", 1000); 
        set("mana_factor", 3);
        
        set_skill("dodge", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("fonxanforce", 100);
        set_skill("fonxansword", 100);
        set_skill("chaos-steps", 100);
        map_skill("force", "fonxanforce");
        map_skill("dodge", "chaos-steps");
        map_skill("sword", "fonxansword");

        set("inquiry", ([
                "here": "�����Ǿ�ʦ���ׯ��ûǮ�������\n",
                "name": "����г�գ��������ܸ����㡣\n",
                "�·�": "����Ҫʲô���ģ�",
        ]) );
        
        set("vendor_goods", ([
                "���޳���": __DIR__"obj/lady_dress",
                "���೤��": __DIR__"obj/green_cloth",
                "�޺����": __DIR__"obj/color_cloth",
        ]) );

        setup();
        add_money("gold", 9);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuqing_sword")->wield();
}

void init()
{
        object ob;

        ::init();
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
                        say( "�ϰ��������λ"
                                + RANK_D->query_respect(ob)
                                + "������Ҫʲô��\n");
                        break;
                case 1:
                        say( "�ϰ������صض���˵��Ҫ��������\n");
                        break;
                case 2:
                        say( "�ϰ�������˵����ū�ҿ��Ǻ�����Ŷ��\n");
                        break;
        }
}

