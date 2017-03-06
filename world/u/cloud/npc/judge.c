// judge.c

inherit NPC;

void create()
{
        set_name("����", ({ "judge" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����ϵı���·��ǿ�������ڴ����Ǯһ�㡣\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "��" : "�͹�����Ǯ���Ҿ����ˡ�\n",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/dagger")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�����ģ�����������\n");
                        break;
                case 1:
                        say( "Ӯ�˿�������������\n");
                        break;
        }
}

void pay_player(object who, int amount)
{
        object ob;

        if( amount < 1 ) amount = 1;
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val ){
                return notify_fail("��Ʒ�����ۼۣ���������ȥ���ְɣ�\n");
                return 0;
        }
        else{
                say("ʲô�� ��ѺС�����õġ�\n"); 
                if( random(10) < 8 ) {
                        say( "����˵��������Ѻ���Ӯ������λ"
                                + RANK_D->query_respect(who)
                                + "�����´�һ�����ˣ�\n");
                }
                else{
                        say( "����˵��������ѺС��Ӯ������λ"
                                + RANK_D->query_respect(who)
                                + "���Ǻ��˵�����������Ӯͷ��\n");
                        pay_player(this_player(), val * 2);
                }
        return 1;
        }
}

