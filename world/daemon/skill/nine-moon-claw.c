inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С����İ�ץ��������ץ��$n��$l",
                "dodge":                -30,
                "parry":                10,
                "force":                200,
                "damage_type":  "ץ��"
         ]),
        ([      "action":               
"$Nʹ��һ�С��������ץ�������ֻ�ָΪצ����������$n��$l",
                "dodge":                -10,
                "parry":                -20,
                "force":                170,
                "damage_type":  "ץ��"
         ]),
([      "action":
"$Nʹ�������׹�צ�ġ�צ�����꡹������Ȱ�����$n��ǰ��һצ����$n��$l",
                "dodge":                -10,
                "parry":                20,
                "force":                150,
                "damage_type":  "ץ��"
         ]),
([      "action":
"$N˫��һ��ʹ�����޵ۿ�צ������׼$n��$l����ץ��",
                "dodge":                10,
                "parry":                -20,
                "force":                250,
                "damage_type":  "ץ��"
         ]),
([      "action":
"$N����ָ�ױ�ͻ�������Ƴ���һ�С����������󡹣�ץ��$n$l",
                "dodge":                -20,
                "parry":                -20,
                "force":                270,
                "damage_type":  "ץ��"
         ]),
([      "action":
"$Nʹ�������������ǡ���˫��ͬʱ��$n��$l��צ����",
                "dodge":                -50,
                "parry":                -10,
                "force":                320,
                "damage_type":  "ץ��"
         ]),
([      "action":
"$N����������һ�С�а������צ��˫�۲����ݳ�",
                "parry":                -40,
                "force":                370,
                "damage_type":  "ץ��"
         ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�����׹�צ��ֻ��Ů�Ӳ��������书��\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������׹�צ������֡�\n");
        if( (int)me->query_skill("nine-moon-force", 1) < 10 )
                return 
notify_fail("��ľ����ľ�����㣬�޷��������׹�צ��\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������̫�����޷��������׹�צ��\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;
        
        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                case 0: return "��������������һ�����죬�����ǹ����������\n";
                case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
                case 2: return "ֻ����$n��$l��������һ�� ...\n";
                }
         }
}
 
string perform_action_file(string action)
{
        return CLASS_D("ninemoon") + "/ninemoonclaw/" + action;
}
                                                                                                                 
