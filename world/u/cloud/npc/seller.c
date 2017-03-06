// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�ӻ���", ({ "seller" }) );
        set("title", "�ӻ���");
        set("gender", "����" );
        set("age", 32);
        set("long", "���ӻ����Ǹ����Ẻ�ӣ����΢Ц��\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("throwing", 30);

        set("inquiry", ([
                "�ӻ���" : "�������ϴ������Ĳ�ҵ��С��������ά�֡�", 
        ]) );

        set("vendor_goods", ([
                "����": "/u/cloud/obj/etc/rope",
 //               "����": "/obj/example/bag",
                "��ʬ��": "/obj/dust",
//"/u/cloud/obj/etc/dust",
        ]) );

        setup();
        add_money("silver", 5);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        for(int i=1; i<=29; i++){
        carry_object("/obj/example/dart")->wield();
        }
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

        if(random(10)<5)
                carry_object("/obj/example/dart")->wield();

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�ӻ���Ц����ӭ��������λ"
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��ʲô��\n");
                        break;
                case 1:
                        say( "�ӻ�����æ���������\n");
                        break;
        }
}

