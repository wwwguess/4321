inherit NPC;
void use_poison();

void create()
{
        set_name("��β��", ({ "snake" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "һ���綾����β�ߡ�\n");

        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 150);
        set("combat_exp", 1000);
        set("bellicosity", 300 );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );

        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob->query_condition("snake_poison") ) return;

        tell_object(ob,
"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("snake_poison", 5);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}
