// zixia-shengong.c 紫霞神功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("zixia-shengong", 1);
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100)
                return notify_fail("你的侠义正气太低了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("紫霞神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"zixia-shengong/" + func;
}

