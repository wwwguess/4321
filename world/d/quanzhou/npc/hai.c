// hai.c ������
// Jay 4/6/96

inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("������", ({"hai gonggong", "hai", "gonggong"}));
        set("title", "����ǧ��");
        set("long",
                "���Ƕ�����̫�ຣ�󸻣���װ�İ������ģ������Ѱ�����֣����ü�����ͷ������̫̫��\n"
        );

        set("gender", "����");
        set("rank_info/respect", "����");

        set("attitude", "heroism");
        set("class", "eunach");

        set("inquiry",([
                "�Թ�"  : (: ask_for_zigong :),
        ]));

        set("age", 60);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_kee", 500);
        set("max_gin", 100);
        set("force", 500);
        set("max_force", 500);
        set("jiali", 100);
        set("combat_exp", 15000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("pixie-jian", 50);

        map_skill("dodge", "pixie-jian");
        map_skill("sword", "pixie-jian");

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 50);
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

        me = this_player();

        if( (string)me->query("gender")=="����" )
                return "����ͬ�����ˣ��αؿ�������ĵ���Ц��\n";

        if( (string)me->query("gender") == "Ů��" )
                return "�����ѷϣ���һ�����Ը������С���˴������֣�Ҫ��Ҫ���ԣ�\n";
        if ((int)me->query_str() > 28 )
                return "��λ�ú����ڴ�׳���Թ��а���հ�����ף����ס�\n";

       me->set_temp("pending/zigong", 1);
        return "�Թ�����λ������ò���ã��α�... ����ϣ����������Ǹ����Թ�֮�󣬲��ɺ�ڣ����������Ѷ�(decide)�������ҡ�\n";
}

int do_decide()
{
        if( !this_player()->query_temp("pending/zigong") )
                return 0;

        message_vision(
                "$Nһҧ�����������¡���Ů��ұ��ۣ���\n\n"
                "$n��������嵽$N����֮�䣬����һ�࣬����\n\n"
                "$N��ʱ�ҽ�һ�����˹�ȥ����\n\n",
                this_player(), this_object() );
        command("chat �ˡ���");
        command("hehe");
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","����");
        this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        this_player()->unconcious();
        return 1;
}

